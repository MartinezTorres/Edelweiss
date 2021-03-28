////////////////////////////////////////////////////////////////////////
// simple XML library
//
// Manuel Martinez (manuel.martinez@kit.edu)
//
// Based on my previous work as part of MOPED, but as it is largely unrelated
// to the algorithm itself, so it gets published here independently. 
// Of course, the XML support of this file is very minimal.
//
// license: LGPLv3

#pragma once

#include "object.hpp"

#include <vector>
#include <map>
#include <fstream>
#include <sstream>

namespace uSnippets {
class sXML {

	void read(std::istream &in) {

		if (in.peek()=='>') in.get();
		while (isspace(in.peek())) in.get();
		while (in.peek() != '<') tag += in.get();
		if (not tag.empty()) { isXML = false; return; }
		in.get();
				
		while (not isspace(in.peek()) and in.peek()!='>' and in.peek()!='=') tag += in.get();
		while (isspace(in.peek())) in.get();		
		
		if (tag=="" or tag[0]=='/' or *tag.rbegin()=='/' ) return;
		
		while (in.peek()!='/') {
			
			std::string propertyName;
			while (not isspace(in.peek()) and in.peek()!='>' and in.peek()!='=') propertyName += in.get();
			while (isspace(in.peek())) in.get();		
			
			if (propertyName=="" or in.peek()!='=') break;

			std::string s;
			while (in.get()!='"');
			do s+=in.get(); while (in.peek()!='"');
			do in.get(); while (isspace(in.peek()));
	
			attributes[propertyName] = s;
		}
		
		while (in.peek()=='>') {
			
			sXML s; 
			s.read(in);
			if (not s.tag.empty() and s.tag[0]=='/') return;
					
			if (s.tag!="")
				children.push_back(s);
		}
		
		while (in.peek() != '>') in.get();
	}
	
	void write(std::ostream &out, int level=0) const { 

		std::string t; for(int x=0; x<level; x++) t+="\t";
		
		if (not isXML) { out << t << tag << std::endl; return; }
		
		out << t << "<" << tag;
		
		for ( std::map<std::string, object>::const_iterator it=attributes.begin(); it!=attributes.end(); it++)
			out << " " << it->first << "=\"" << it->second << "\"";
		
		if (children.empty()) { out << " />" << std::endl; return; }
			
		out << ">" << std::endl;
		for (std::vector<sXML>::const_iterator it=children.begin(); it!=children.end(); it++)
			it->write(out, level+1);
		out << t << "</" << tag << ">" << std::endl;
	}
	
public:
	bool isXML;
	std::string tag;
	std::vector<sXML> children;
	std::map<std::string, object> attributes;

	sXML(std::string tag = "") : isXML(true),tag(tag) {};
	
	friend std::istream& operator>> (std::istream &in, sXML &sxml) {
		
		sxml = sXML();
		std::ios_base::iostate originalExceptions = in.exceptions();
		try {
			in.exceptions(std::ios_base::eofbit | std::ios_base::failbit | std::ios_base::badbit);
			sxml.read( in );
		} catch (std::ifstream::failure e) {
			sxml = sXML();
		}
		in.exceptions(originalExceptions);
		return in;
	}

	friend std::ostream& operator<< (std::ostream &out, const sXML &s) { s.write( out ); return out; } 	
	
	object &operator[] ( const std::string s ) { return attributes[s]; } 
	const object operator[] ( const std::string s ) const { std::map<std::string, object>::const_iterator f=attributes.find(s); return f!=attributes.end()?f->second:object(""); } 
	
	std::vector<sXML> &operator()() { return children; }
	const std::vector<sXML> &operator()() const { return children; }

	sXML &operator()(const std::string id) { 
		for (unsigned int i=0; i<children.size(); i++) 
			if (children[i].tag==id) 
				return children[i];
		children.push_back(sXML(id));
		return children.back();
	}

	const sXML &operator()(const std::string id) const { 
		for (unsigned int i=0; i<children.size(); i++) 
			if (children[i].tag==id) 
				return children[i];
		return *this;
	}
};
}

