//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "edgepileup1dTestApp.h"
#include "edgepileup1dApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
edgepileup1dTestApp::validParams()
{
  InputParameters params = edgepileup1dApp::validParams();
  return params;
}

edgepileup1dTestApp::edgepileup1dTestApp(InputParameters parameters) : MooseApp(parameters)
{
  edgepileup1dTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

edgepileup1dTestApp::~edgepileup1dTestApp() {}

void
edgepileup1dTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  edgepileup1dApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"edgepileup1dTestApp"});
    Registry::registerActionsTo(af, {"edgepileup1dTestApp"});
  }
}

void
edgepileup1dTestApp::registerApps()
{
  registerApp(edgepileup1dApp);
  registerApp(edgepileup1dTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
edgepileup1dTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  edgepileup1dTestApp::registerAll(f, af, s);
}
extern "C" void
edgepileup1dTestApp__registerApps()
{
  edgepileup1dTestApp::registerApps();
}
