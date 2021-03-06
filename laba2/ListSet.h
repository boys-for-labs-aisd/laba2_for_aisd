#pragma once

#include <iostream>

class ST {
private:
	unsigned char letter;
	ST* next;
public:
	friend class Set;
	ST(unsigned char l, ST* n) : letter(l), next(n) {}
	~ST() { delete next; }
};

class Set
{
private:
	static int N, cnt;
	int n;
	char S;
	ST* A;
	void Generator(int, ST*);

public:
	Set operator| (const Set&) const;
	Set operator& (const Set&) const;
	Set operator~ () const;
	Set& operator= (const Set&);
	Set& operator= (Set&& B) noexcept;

	Set& operator &= (const Set&);
	Set& operator |= (const Set&);

	friend std::ostream& operator<< (std::ostream&, Set&);

	bool isInSet(unsigned char) const;
	void Show();
	int power() { return n; }
	static void ZeroingCounter();
	Set(char);
	Set();
	Set(const Set&);
	Set(Set&& B) noexcept;
	Set(int);
	~Set();
};