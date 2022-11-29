#include "edgepileup1dApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
edgepileup1dApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

edgepileup1dApp::edgepileup1dApp(InputParameters parameters) : MooseApp(parameters)
{
  edgepileup1dApp::registerAll(_factory, _action_factory, _syntax);
}

edgepileup1dApp::~edgepileup1dApp() {}

void
edgepileup1dApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"edgepileup1dApp"});
  Registry::registerActionsTo(af, {"edgepileup1dApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
edgepileup1dApp::registerApps()
{
  registerApp(edgepileup1dApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
edgepileup1dApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  edgepileup1dApp::registerAll(f, af, s);
}
extern "C" void
edgepileup1dApp__registerApps()
{
  edgepileup1dApp::registerApps();
}
