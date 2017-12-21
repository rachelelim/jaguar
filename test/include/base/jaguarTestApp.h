#ifndef JAGUARTESTAPP_H
#define JAGUARTESTAPP_H

#include "MooseApp.h"

class jaguarTestApp;

template <>
InputParameters validParams<jaguarTestApp>();

class jaguarTestApp : public MooseApp
{
public:
  jaguarTestApp(InputParameters parameters);
  virtual ~jaguarTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* JAGUARTESTAPP_H */
