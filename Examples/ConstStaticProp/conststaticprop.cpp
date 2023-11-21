/**
 *  cppclassinphp.cpp
 *  @author Jasper van Eck<jasper.vaneck@copernica.com>
 *
 *  An example file to show the working of using a C++ class in PHP.
 */

#include "conststaticprop.h"
/**
 *  Namespace to use
 */
using namespace std;

class MyTestExt : public Php::Base
{

public:
    MyTestExt() {}

    virtual ~MyTestExt() {}

    virtual void __construct() {}

};


// Symbols are exported according to the "C" language
extern "C"
{
    // export the "get_module" function that will be called by the Zend engine
    PHPCPP_EXPORT void *get_module()
    {
        // create extension
        static Php::Extension extension("my_const_static_prop", "0.1a");

        // we are going to define a class
        Php::Class<MyTestExt> myTestExt("MyTestClass");

        // add methods to it
        myTestExt.method<&MyTestExt::__construct>("__construct", Php::Private);

        // add properties to it
        myTestExt.property("version", "v0.01-alpha", Php::Const);
        myTestExt.constant("PI", 3.14159265);
        myTestExt.add(Php::Constant("IMISNULL"));
        myTestExt.property("exp", 2.71828182846, Php::Static);

        // add the class to the extension
        extension.add(myTestExt);

        // return the extension module
        return extension.module();
    }
}
