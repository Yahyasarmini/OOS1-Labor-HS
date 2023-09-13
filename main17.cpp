
#include <iostream>
#include <string>
using namespace std;

void p(string s, bool nl = true) {
	cout << s << " ";
	if (nl) { cout << endl; }
}

class A {
public:
	    void f_1() { p("A::f_1()"); }
       virtual void f_2() { p("A::f_2()"); }
	    void f_3() { p("A::f_3()"); }
	     void f_4() { p("A::f_4()", false); f_2(); }
};

class B : public A {
public:
	void f_1() { p("B::f_1()"); }
	void f_2() { p("B::f_2()"); }
	void f_3() { p("B::f_3()"); }
	virtual void f_4() { p("B::f_4()", false); f_2(); }
};

class C : public B {
public:
	void f_1() { p("C::f_1()"); }
	void f_2() { p("C::f_2()"); }
	virtual void f_3() { p("C::f_3()"); }
	void f_4() { p("C::f_4()", false); f_2(); }
};

class D : public C {
public:
	void f_1() { p("D::f_1()"); }
    void f_2() { p("D::f_2()"); }
	void f_3() { p("D::f_3()"); }
};

int main(int argc, char *argv[])  {
	D d;
	A * p_a = &d;
	B * p_b = &d;
	C * p_c = &d;
	p_a->f_1();
	p_b->f_1();
	p_c->f_1();
	p_a->f_2();
	p_b->f_2();
	p_c->f_2();
	p_a->f_3();
	p_b->f_3();
	p_c->f_3();
	p_a->f_4();
	p_b->f_4();
	p_c->f_4();
}
/*
A::f_1()
B::f_1()
C::f_1()
D::f_2()
D::f_2()
D::f_2()
A::f_3()
B::f_3()
D::f_3()
A::f_4() D::f_2()
C::f_4() D::f_2()
C::f_4() D::f_2()
*/

