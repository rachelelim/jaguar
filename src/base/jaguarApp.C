#include "jaguarApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

#include "MovingDirac.h" //Custom DiracKernel of moving heat source (DW)
#include "MovingDirac2d.h" //Custom DiracKernel of 2d moving heat source (DW)

template <>
InputParameters
validParams<jaguarApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

jaguarApp::jaguarApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  jaguarApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  jaguarApp::associateSyntax(_syntax, _action_factory);
}

jaguarApp::~jaguarApp() {}

// External entry point for dynamic application loading
extern "C" void
jaguarApp__registerApps()
{
  jaguarApp::registerApps();
}
void
jaguarApp::registerApps()
{
  registerApp(jaguarApp);
}

void
jaguarApp::registerObjectDepends(Factory & /*factory*/)
{
}

// External entry point for dynamic object registration
extern "C" void
jaguarApp__registerObjects(Factory & factory)
{
  jaguarApp::registerObjects(factory);
}
void
jaguarApp::registerObjects(Factory & factory)
{
  registerDiracKernel(MovingDirac); // <- registration (DW)
  registerDiracKernel(MovingDirac2d); // <- registration (DW)
}

void
jaguarApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
jaguarApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  jaguarApp::associateSyntax(syntax, action_factory);
}
void
jaguarApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
