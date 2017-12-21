#ifndef JAGUARAPP_H
#define JAGUARAPP_H

#include "MooseApp.h"

class jaguarApp;

template <>
InputParameters validParams<jaguarApp>();

class jaguarApp : public MooseApp
{
public:
  jaguarApp(InputParameters parameters);
  virtual ~jaguarApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* JAGUARAPP_H */
