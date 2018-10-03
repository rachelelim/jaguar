#include "jaguarApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

#include "MovingDirac.h" //Custom DiracKernel of moving heat source (DW)
#include "MovingDirac2d.h" //Custom DiracKernel of 2d moving heat source (DW)
#include "MovingDirac3d.h" //Custom DiracKernel of 3d moving heat source (DW)
#include "MovingDirac3dSingleBead.h" //Custom DiracKernel of 3d single bead moving heat source (DW)
#include "MovingDirac3dHatch.h" //Custom DiracKernel of 3d hatch moving heat source (DW)
#include "MovingDirac3dHatch_case1_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_case1_contour.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
///////////////ThinWall//////////////
#include "MovingDirac3dHatch_IN718_500_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_IN718_500_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_IN718_500_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_IN718_665_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_IN718_665_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_IN718_665_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_IN718_760_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_IN718_760_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_IN718_760_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_IN718_855_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_IN718_855_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_IN718_855_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_500_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_AlSi10Mg_500_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_500_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_665_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_AlSi10Mg_665_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_665_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_760_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_AlSi10Mg_760_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_760_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_855_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_AlSi10Mg_855_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_855_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_960_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_AlSi10Mg_960_contour1.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_AlSi10Mg_960_contour2.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_Ti64_665_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_Ti64_665_contour.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_Ti64_760_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_Ti64_760_contour.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_Ti64_855_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_Ti64_855_contour.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
#include "MovingDirac3dHatch_Ti64_950_raster.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation raster
#include "MovingDirac3dHatch_Ti64_950_contour.h" //Custom DiracKernel of 3d hatch moving heat source (DW) 45degree rotation contour
///////////////////////////////////
#include "MovingDirac3d_overhang_a.h" //Custom DiracKernel of 3d overhang moving heat source (DW)
#include "MovingDirac3d_multilayers.h" //Custom DiracKernel of 3d multilayers moving heat source(DW)
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
  registerDiracKernel(MovingDirac3d); // <- registration (DW)
  registerDiracKernel(MovingDirac3dSingleBead); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_case1_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_case1_contour); // <- registration (DW)
  ///////////////ThinWall//////////////
  registerDiracKernel(MovingDirac3dHatch_IN718_500_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_500_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_500_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_665_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_665_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_665_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_760_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_760_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_760_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_855_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_855_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_IN718_855_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_500_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_500_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_500_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_665_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_665_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_665_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_760_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_760_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_760_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_855_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_855_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_855_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_960_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_960_contour1); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_AlSi10Mg_960_contour2); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_665_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_665_contour); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_760_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_760_contour); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_855_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_855_contour); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_950_raster); // <- registration (DW)
  registerDiracKernel(MovingDirac3dHatch_Ti64_950_contour); // <- registration (DW)
  ///////////////////////////////////

  registerDiracKernel(MovingDirac3d_overhang_a); // <- registration (DW)
  registerDiracKernel(MovingDirac3d_multilayers); // <- registration (DW)
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
