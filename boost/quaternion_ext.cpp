/*****************************************************************************
*
* pyobjcryst        by DANSE Diffraction group
*                   Simon J. L. Billinge
*                   (c) 2009 Trustees of the Columbia University
*                   in the City of New York.  All rights reserved.
*
* File coded by:    Chris Farrow
*
* See AUTHORS.txt for a list of people who contributed.
* See LICENSE.txt for license information.
*
******************************************************************************
*
* boost::python bindings to ObjCryst::Quaternion.  
* 
* Changes from ObjCryst++
* - IO is not wrapped yet
* - Q0, Q1, Q2 and Q3 are wrapped as properties, rather than functions.
*
* $Id$
*
*****************************************************************************/

#include "ObjCryst/Molecule.h"

#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/args.hpp>

#include <set>

namespace bp = boost::python;
using namespace boost::python;
using namespace ObjCryst;

namespace {

float getQ0(const Quaternion& q)
{
    return q.Q0();
}

float getQ1(const Quaternion& q)
{
    return q.Q1();
}

float getQ2(const Quaternion& q)
{
    return q.Q2();
}

float getQ3(const Quaternion& q)
{
    return q.Q3();
}

void setQ0(Quaternion& q, float val)
{
    q.Q0() = val;
}

void setQ1(Quaternion& q, float val)
{
    q.Q1() = val;
}

void setQ2(Quaternion& q, float val)
{
    q.Q2() = val;
}

void setQ3(Quaternion& q, float val)
{
    q.Q3() = val;
}

} // namespace

void wrap_quaternion()
{

    class_<Quaternion>("Quaternion")
        .def(init<const float, const float, const float, const float, bool>(
            (bp::arg("q0"), bp::arg("q1"), bp::arg("q2"), bp::arg("q3"),
             bp::arg("unit")=true
            ))
            )
        .def("GetConjugate", &Quaternion::GetConjugate)
        .def("RotateVector", &Quaternion::RotateVector,
            (bp::arg("v1"), bp::arg("v2"), bp::arg("v3")))
        .def("Normalize", &Quaternion::Normalize)
        .def("GetNorm", &Quaternion::GetNorm)
        .def("RotationQuaternion", &Quaternion::RotationQuaternion,
            (bp::arg("ang"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3")))
        .staticmethod("RotationQuaternion")
        .add_property("Q0", &getQ0, &setQ0)
        .add_property("Q1", &getQ1, &setQ1)
        .add_property("Q2", &getQ2, &setQ2)
        .add_property("Q3", &getQ3, &setQ3)
        .def(self * self)
        .def(self *= self)
        ;
}
