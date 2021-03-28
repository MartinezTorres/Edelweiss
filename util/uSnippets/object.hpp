////////////////////////////////////////////////////////////////////////
// object.hpp: One class to rule it all
//
// Manuel Martinez (manuel.martinez@kit.edu)
//
// license: LGPLv3

#pragma once
#include <algorithm>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <cstring>
#include <cctype>

namespace cv { template<class T> struct Mat_; }
namespace uSnippets {

struct object;
struct Token : public std::string {

	std::string &parent;
	std::string::iterator i1, i2;
	
	Token(std::string &parent, std::string::iterator &it) : parent(parent) {

		while (it!=parent.end() and std::isspace(*it)) it++;
		if (it==parent.end()) { parent+=(" \"\""); it=parent.end()-2; }
		i1 = it;
		if (it!=parent.end() and *it == '"') {
			for (int skip=true; it!=parent.end() and (skip or *it!='"'); skip = *it=='\\') { if (not skip) push_back(*it); it++; }
			if (it!=parent.end()) it++;
		} else {
			while (it!=parent.end() and not std::isspace(*it)) push_back(*it++);
		}
		i2 = it;
	}

	static std::string escape(const std::string &s) {
		if (not s.empty() and std::none_of(s.begin(), s.end(), [](int i){return std::isspace(i);})) 
			return s;
		
		std::string ret = "\"";
		for (auto c : s) ret.append(c=='\\' or c=='"','\\').append(1,c); 
		return ret+"\"";
	}

	template<class T, class O = object> Token &operator=(const T& t) { this->assign(O(t)); parent.replace(i1,i2,escape(*this)); return *this; }
	template<class T, class O = object> operator T() && { T t = O(*this); return std::move(t);}
};

struct object : public std::string {
	
	typedef std::stringstream SS;

	using std::string::string;

	object() = default;
	object(const object & ) = default; object& operator=(const object & ) = default;
	object(      object &&) = default; object& operator=(      object &&) = default;

	template<class T> object(const T &v) { SS ss; ss.precision(15); ss << v; assign(ss.str()); }

	template<class T> T get() const { SS ss(*this); T v; ss >> v; return v; }	
	template<class T> operator T() const { return get<T>(); }

	template<class T> object operator+(const T &t) const { return std::string(*this) + object(t); }
	
	template<typename T> object &operator<<(const T &v) { append(object(v)); return *this; }
	template<typename T> object &operator>>(T &v) { SS ss(*this); ss >> v; assign(ss.tellg()!=-1?substr(ss.tellg()):std::string("")); return *this; }

	Token token(int i) { auto it = begin(); while(i--) Token(*this,it); return Token(*this,it); }
	const object token(int i) const { object obj(*this); auto it = obj.begin(); while(i--) Token(obj,it); return object(Token(obj,it)); }
};

}
