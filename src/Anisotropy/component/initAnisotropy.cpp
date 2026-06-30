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
#include <Anisotropy/component/initAnisotropy.h>
#include <sofa/core/ObjectFactory.h>

#include <sofa/helper/system/PluginManager.h>
using sofa::helper::system::PluginManager;

#include <fstream>

namespace anisotropy
{

namespace forcefield
{
extern void registerTetrahedronAnisotropicForceField(sofa::core::ObjectFactory* factory);
}

//Here are just several convenient functions to help user to know what contains the plugin

extern "C" {
    SOFA_ANISOTROPY_API void initExternalModule();
    SOFA_ANISOTROPY_API const char* getModuleName();
    SOFA_ANISOTROPY_API const char* getModuleVersion();
    SOFA_ANISOTROPY_API const char* getModuleLicense();
    SOFA_ANISOTROPY_API const char* getModuleDescription();
    SOFA_ANISOTROPY_API const char* getModuleComponentList();
    SOFA_ANISOTROPY_API void registerObjects(sofa::core::ObjectFactory* factory);
}

void init()
{
    static bool first = true;
    if (first)
    {
        first = false;
    }

    // make sure that this plugin is registered into the PluginManager
    sofa::helper::system::PluginManager::getInstance().registerPlugin(MODULE_NAME);
}

void initExternalModule()
{
    init();
}

const char* getModuleName()
{
  return MODULE_NAME;
}

const char* getModuleVersion()
{
    return "1.0";
}

const char* getModuleLicense()
{
    return "GPL";
}

const char* getModuleDescription()
{
    return "The Anisotropy plugin builds components for anisotropic simulations.";
}

void registerObjects(sofa::core::ObjectFactory* factory)
{
    forcefield::registerTetrahedronAnisotropicForceField(factory);
}

} // namespace anisotropy
