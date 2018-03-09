// Gmsh project created on Fri Mar  2 13:51:56 2018

//Input
boxlength = 4;
boxwidth = 0.4;
baseheight = 0.18;
layerthickness = 0.03;
numelementL = 800;
numelementW = 100;
numelementH = 60;
numelementlayer = 10;


//Create 2D rectangular mesh
Point(1) = {0, 0, 0, 1.0};
Point(2) = {boxlength, 0, 0, 1.0};
Point(3) = {boxlength, boxwidth, 0, 1.0};
Point(4) = {0, boxwidth, 0, 1.0};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

Line Loop(1) = {1,2,3,4};
Plane Surface(1) = {1};

Transfinite Line{2,4} = numelementW+1;
Transfinite Line{1,3} = numelementL+1;
Transfinite Surface{1};
Recombine Surface{1};

//Make base by extrusion.
newEntities[] = 
Extrude { 0,0,baseheight}
{
	Surface{1};
	Layers{numelementH};
	Recombine;
};

//Make layer 1 by extrusion.
newEntities[] = 
Extrude { 0,0,layerthickness}
{
	Surface{26};
	Layers{numelementlayer};
	Recombine;
};

//Make layer 2 by extrusion.
newEntities[] = 
Extrude { 0,0,layerthickness}
{
	Surface{48};
	Layers{numelementlayer};
	Recombine;
};

//Make layer 3 by extrusion.
newEntities[] = 
Extrude { 0,0,layerthickness}
{
	Surface{70};
	Layers{numelementlayer};
	Recombine;
};

//Make layer 4 by extrusion.
//newEntities[] = 
//Extrude { 0,0,layerthickness}
//{
//	Surface{92};
//	Layers{numelementlayer};
//	Recombine;
//};

//Assign name for B.C and subdomain

Physical Surface("bottom_outlet") = {1};
Physical Surface("base_top") = {26};
Physical Surface("layer1_top") = {48};
Physical Surface("layer2_top") = {70};
Physical Surface("layer3_top") = {92};
//Physical Surface("layer4_top") = {114};
Physical Surface("sidewall_right") = {13,35,57,79};
Physical Surface("sidewall_left") = {21,43,65,87};
Physical Surface("end_back") = {25,47,69,91};
Physical Surface("end_front") = {17,39,61,83};
Physical Volume("base") = {1};
Physical Volume("layer_1") = {2};
Physical Volume("layer_2") = {3};
Physical Volume("layer_3") = {4};
//Physical Volume("layer_4") = {5};