// emp.h -- header file for abstr_emp class and children
#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>


class abstr_emp
{
private:
    std::string fname;      // abstr_emp's first name
    std::string lname;      // abstr_emp's last name
    std::string job;
public:
    abstr_emp()
        : fname(), lname(), job() { std::cout << "--> abstr_emp()\n"; }
    abstr_emp(const std::string& fn, const std::string& ln,
              const std::string& j)
        : fname(fn), lname(ln), job(j)
        { std::cout << "--> abstr_emp(const string&, const string&, const string&)\n"; }
    virtual void ShowAll() const;       // labels and shows all data
    virtual void SetAll();              // prompts user for values

// friends
    // just displays first and last name
    friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
    virtual ~abstr_emp() = 0;       // virtual base class
};

class employee : public abstr_emp
{
public:
    employee()
        : abstr_emp()
        { std::cout << "--> employee()\n"; }
    employee(const std::string& fn, const std::string& ln,
             const std::string& j)
        : abstr_emp(fn, ln, j)
        { std::cout << "--> employee(const string&, const string&, const string&)\n"; }
    virtual void ShowAll() const;
    virtual void SetAll();
    ~employee() { std::cout << "--> ~employee()\n"; }
};


class manager : virtual public abstr_emp
{
private:
    int inchargeof;     // number of abstr_emps managed
protected:
    int InChargeOf() const      // input
        { return inchargeof; }
    int& InChargeOf()           // output
        { return inchargeof; }
public:
    manager()
        : abstr_emp()
        , inchargeof(0)
        { std::cout << "--> manager()\n"; }
    manager(const std::string& fn, const std::string& ln,
            const std::string& j, int ico = 0)
        : abstr_emp(fn, ln, j)
        , inchargeof(ico)
        { std::cout << "--> manager(const string&, const string&, const string&, int)\n"; }
    manager(const abstr_emp& e, int ico)
        : abstr_emp(e)
        , inchargeof(ico)
        { std::cout << "--> manager(const abstr_emp&, in)\n"; }
    manager(const manager& m)
        : abstr_emp(m)
        , inchargeof(m.inchargeof)
        { std::cout << "--> manager(const manager&)\n"; }
    virtual void ShowAll() const;
    virtual void SetAll();
    ~manager() { std::cout << "--> ~manager()\n"; }
};


class fink : virtual public abstr_emp
{
private:
    std::string reportsto;      // to whom fink reports
protected:
    const std::string& ReportsTo() const
        { return reportsto; }
    std::string& ReportsTo()
        { return reportsto; }
public:
    fink()
        : abstr_emp()
        , reportsto()
        { std::cout << "--> fink()\n"; }
    fink(const std::string& fn, const std::string& ln,
         const std::string& j, const std::string& rpo)
        : abstr_emp(fn, ln, j)
        , reportsto(rpo)
        { std::cout << "--> fink(const string&, const string&, const string&, const string&)\n"; }
    fink(const abstr_emp& e, const std::string& rpo)
        : abstr_emp(e)
        , reportsto(rpo)
        { std::cout << "--> fink(const abstr_emp&, const string&)\n"; }
    fink(const fink& e)
        : abstr_emp(e)
        , reportsto(e.reportsto)
        { std::cout << "--> fink(const fink&)\n"; }
    virtual void ShowAll() const;
    virtual void SetAll();
    ~fink() { std::cout << "--> ~fink()\n"; }
};


class highfink : public manager, public fink   // management fink
{
public:
    highfink()
        : abstr_emp()
        , manager()
        , fink()
        { std::cout << "--> highfink()\n"; }
    highfink(const std::string& fn, const std::string& ln,
             const std::string& j, const std::string& rpo,
             int ico)
        : abstr_emp(fn, ln, j)
        , manager(fn, ln, j, ico)
        , fink(fn, ln, j, rpo)
        { std::cout << "--> highfink(const string&, const string&, const string&, const string&, int)\n"; }
    highfink(const abstr_emp& e, const std::string& rpo, int ico)
        : abstr_emp(e)
        , manager(e, ico)
        , fink(e, rpo)
        { std::cout << "--> highfink(const abstr_emp&, const string&, int)\n"; }
    highfink(const fink& f, int ico)
        : abstr_emp(f)
        , manager(f, ico)
        , fink(f)
        { std::cout << "--> highfink(const fink&, int)\n"; }
    highfink(const manager& m, const std::string& rpo)
        : abstr_emp(m)
        , manager(m)
        , fink(m, rpo)
        { std::cout << "--> highfink(const manager&, const string&)\n"; }
    highfink(const highfink& h)
        : abstr_emp(h)
        , manager(h)
        , fink(h)
        { std::cout << "--> highfink(const highfink&)\n"; }
    virtual void ShowAll() const;
    virtual void SetAll();
    ~highfink() { std::cout << "--> ~highfink()\n"; }
};


#endif /*EMP_H_*/
