
// Lab Exercise 4.

#include "set.h"
#include <cctype>

bool set::equal(const std::string& s1, const std::string& s2) {
	if (s1.size() != s2.size())
		return false;
	
	for (size_t i = 0; i < s1.size(); i++) {
		if ((char)  tolower(s1[i]) != (char) tolower(s2[i]))
			return false;
	}

	return true;
}

std::string tolower(std::string const &input) {
	std::string res;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z')
			res += input[i] + 32;
		else
			res += input[i];
	}
	return (res);
}

bool set::contains(const std::string& el) const {
	// check for the lower case
	std::string el_lower = tolower(el);
	
	for (size_t i = 0; i < data.size(); i++) {
		if (el_lower == tolower(data[i]))
			return true;
	}
	return false;
}

bool set::insert(const std::string& el) {
	
	if (contains(el)== true)
		return false;
	   
	else {
		data.push_back(el);
		return true;
	}
}

size_t set::insert(const set& s) {
	//number of elements inserted
	size_t inserted = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (insert(*it))
			inserted++;
	}
	return inserted;
}

bool set::remove(const std::string& el) {
	//return true if el was found and removed, otherwise false
	//find el; std::swap with back() of the vector; use pop_back();
	if (contains(el) == true) {
		auto it = data.begin();
		while (it != data.end()) {
			if (*it == el)
				break;
			it++;
		}
		data.erase(it);
		return true;
	}
	return false;
}

size_t set::remove(const set& s) {
	size_t removed = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (remove(*it))
			removed++;
	}
	return removed;
		//return the number of elements that were removed
}

std::ostream& operator << (std::ostream& out, const set& s) {
	//out << "set:";
	// use set::const_iterator
	out<<"{";
  
  for (std::vector<std::string>::const_iterator i = s.begin(); i != s.end(); i++) {
		if (i==s.begin())
    out << *i;
    else
		out << "," << *i;
	}
  out<<"}";
	return out;
}

bool subset(const set& s1, const set& s2) {
	//return true of set s1 is a subset of set s2
	for (auto it = s1.begin(); it != s1.end(); it++) {
		if (s2.contains(*it) == false)
			return (false);
	}
	return (true);
}

