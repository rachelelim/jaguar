#include "jaguarTestApp.h"
#include "jaguarApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<jaguarTestApp>()
{
  InputParameters params = validParams<jaguarApp>();
  return params;
}

jaguarTestApp::jaguarTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  jaguarApp::registerObjectDepends(_factory);
  jaguarApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  jaguarApp::associateSyntaxDepends(_syntax, _action_factory);
  jaguarApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    jaguarTestApp::registerObjects(_factory);
    jaguarTestApp::associateSyntax(_syntax, _action_factory);
  }
}

jaguarTestApp::~jaguarTestApp() {}

// External entry point for dynamic application loading
extern "C" void
jaguarTestApp__registerApps()
{
  jaguarTestApp::registerApps();
}
void
jaguarTestApp::registerApps()
{
  registerApp(jaguarApp);
  registerApp(jaguarTestApp);
}

// External entry point for dynamic object registration
extern "C" void
jaguarTestApp__registerObjects(Factory & factory)
{
  jaguarTestApp::registerObjects(factory);
}
void
jaguarTestApp::registerObjects(Factory & /*factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
jaguarTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  jaguarTestApp::associateSyntax(syntax, action_factory);
}
void
jaguarTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
