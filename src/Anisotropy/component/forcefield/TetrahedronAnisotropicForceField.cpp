/******************************************************************************
*                    Anisotropy plugin for SOFA                               *
*                         version 1.0                                         *
*                       Copyright © Inria                                     *
*                       All rights reserved                                   *
*                       2024                                                  *
*                                                                             *
* This software is under the GNU General Public License v2 (GPLv2)            *
*            https://www.gnu.org/licenses/licenses.en.html                    *
*                                                                             *
*                                                                             *
*                                                                             *
* Authors: Felix Vanneste                                                     *
*                                                                             *
* Contact information: felix.vanneste@inria.information                       *
******************************************************************************/
#define ANISOTROPY_COMPONENT_FORCEFIELD_TETRAHEDRONANISOTROPICFORCEFIELD_CPP
#include <Anisotropy/component/forcefield/TetrahedronAnisotropicForceField.inl>

#include <sofa/defaulttype/VecTypes.h>
#include <sofa/core/ObjectFactory.h>

namespace anisotropy::forcefield
{

using namespace sofa::defaulttype;
using namespace sofa::core;

void registerTetrahedronAnisotropicForceField(ObjectFactory* factory)
{
    factory->registerObjects(ObjectRegistrationData("Anisotropic tetrahedral finite elements.")
                            .add<  TetrahedronAnisotropicForceField<Vec3Types> >());
}

template class SOFA_ANISOTROPY_API TetrahedronAnisotropicForceField<Vec3Types>;

}
