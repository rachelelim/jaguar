// Gmsh project created on Tue Feb 27 17:50:16 2018
//+
Point(1) = {0, 0, 0, 1.0};
//+
Point(2) = {0.5, 0, 0, 1.0};
//+
Point(3) = {0, 0, 0.09, 1.0};
//+
Point(4) = {0.5, 0, 0.09, 1.0};
//+
Point(5) = {0, 0, 0.12, 1.0};
//+
Point(6) = {0.5, 0, 0.12, 1.0};
//+
Point(7) = {0, 0, 0.15, 1.0};
//+
Point(8) = {0.5, 0, 0.15, 1.0};
//+
Point(9) = {0, 0, 0.18, 1.0};
//+
Point(10) = {0.5, 0, 0.18, 1.0};
//+
Point(11) = {0, 0, 0.21, 1.0};
//+
Point(12) = {0.5, 0, 0.21, 1.0};
//+
Point(13) = {0, 0.25, 0, 1.0};
//+
Point(14) = {0.5, 0.25, 0, 1.0};
//+
Point(15) = {0, 0.25, 0.09, 1.0};
//+
Point(16) = {0.5, 0.25, 0.09, 1.0};
//+
Point(17) = {0, 0.25, 0.12, 1.0};
//+
Point(18) = {0.5, 0.25, 0.12, 1.0};
//+
Point(19) = {0, 0.25, 0.15, 1.0};
//+
Point(20) = {0.5, 0.25, 0.15, 1.0};
//+
Point(21) = {0, 0.25, 0.18, 1.0};
//+
Point(22) = {0.5, 0.25, 0.18, 1.0};
//+
Point(23) = {0, 0.25, 0.21, 1.0};
//+
Point(24) = {0.5, 0.25, 0.21, 1.0};//+
Line(1) = {1, 2};
//+
Line(2) = {2, 14};
//+
Line(3) = {14, 13};
//+
Line(4) = {13, 1};
//+
Line(5) = {3, 4};
//+
Line(6) = {4, 16};
//+
Line(7) = {16, 15};
//+
Line(8) = {15, 3};
//+
Line(9) = {6, 6};
//+
Line(10) = {6, 18};
//+
Line(11) = {18, 17};
//+
Line(12) = {17, 5};
//+
Line(13) = {5, 6};
//+
Line(14) = {8, 20};
//+
Line(15) = {20, 19};
//+
Line(16) = {19, 7};
//+
Line(17) = {7, 8};
//+
Line(18) = {10, 22};
//+
Line(19) = {22, 21};
//+
Line(20) = {21, 9};
//+
Line(21) = {9, 10};
//+
Line(22) = {12, 24};
//+
Line(23) = {24, 23};
//+
Line(24) = {23, 11};
//+
Line(25) = {11, 12};
//+
Line(26) = {3, 1};
//+
Line(27) = {4, 2};
//+
Line(28) = {16, 14};
//+
Line(29) = {15, 13};
//+
Line(30) = {5, 3};
//+
Line(31) = {6, 4};
//+
Line(32) = {18, 16};
//+
Line(33) = {17, 15};
//+
Line(34) = {7, 5};
//+
Line(35) = {8, 6};
//+
Line(36) = {20, 18};
//+
Line(37) = {19, 17};
//+
Line(38) = {9, 7};
//+
Line(39) = {10, 8};
//+
Line(40) = {22, 20};
//+
Line(41) = {21, 19};
//+
Line(42) = {11, 9};
//+
Line(43) = {12, 10};
//+
Line(44) = {24, 22};
//+
Line(45) = {23, 21};
//+
Line Loop(1) = {1, 2, 3, 4};
//+
Plane Surface(1) = {1};
//+
Line Loop(2) = {5, 6, 7, 8};
//+
Plane Surface(2) = {2};
//+
Line Loop(3) = {13, 10, 11, 12};
//+
Plane Surface(3) = {3};
//+
Line Loop(4) = {17, 14, 15, 16};
//+
Plane Surface(4) = {4};
//+
Line Loop(5) = {21, 18, 19, 20};
//+
Plane Surface(5) = {5};
//+
Line Loop(6) = {25, 22, 23, 24};
//+
Plane Surface(6) = {6};
//+
Line Loop(7) = {26, 1, -27, -5};
//+
Plane Surface(7) = {7};
//+
Line Loop(8) = {30, 5, -31, -13};
//+
Plane Surface(8) = {8};
//+
Line Loop(9) = {34, 13, -35, -17};
//+
Plane Surface(9) = {9};
//+
Line Loop(10) = {38, 17, -39, -21};
//+
Plane Surface(10) = {10};
//+
Line Loop(11) = {42, 21, -43, -25};
//+
Plane Surface(11) = {11};
//+
Line Loop(12) = {3, -29, -7, 28};
//+
Plane Surface(12) = {12};
//+
Line Loop(13) = {32, 7, -33, -11};
//+
Plane Surface(13) = {13};
//+
Line Loop(14) = {36, 11, -37, -15};
//+
Plane Surface(14) = {14};
//+
Line Loop(15) = {40, 15, -41, -19};
//+
Plane Surface(15) = {15};
//+
Line Loop(16) = {44, 19, -45, -23};
//+
Plane Surface(16) = {16};
//+
Line Loop(17) = {29, 4, -26, -8};
//+
Plane Surface(17) = {17};
//+
Line Loop(18) = {33, 8, -30, -12};
//+
Plane Surface(18) = {18};
//+
Line Loop(19) = {37, 12, -34, -16};
//+
Plane Surface(19) = {19};
//+
Line Loop(20) = {41, 16, -38, -20};
//+
Plane Surface(20) = {20};
//+
Line Loop(21) = {45, 20, -42, -24};
//+
Plane Surface(21) = {21};
//+
Line Loop(22) = {2, -28, -6, 27};
//+
Plane Surface(22) = {22};
//+
Line Loop(23) = {31, 6, -32, -10};
//+
Plane Surface(23) = {23};
//+
Line Loop(24) = {35, 10, -36, -14};
//+
Plane Surface(24) = {24};
//+
Line Loop(25) = {39, 14, -40, -18};
//+
Plane Surface(25) = {25};
//+
Line Loop(26) = {43, 18, -44, -22};
//+
Plane Surface(26) = {26};
//+
Surface Loop(1) = {22, 1, 7, 17, 12, 2};
//+
Volume(1) = {1};
//+
Surface Loop(2) = {23, 8, 18, 13, 2, 3};
//+
Volume(2) = {2};
//+
Surface Loop(3) = {24, 9, 19, 14, 3, 4};
//+
Volume(3) = {3};
//+
Surface Loop(4) = {25, 10, 20, 15, 4, 5};
//+
Volume(4) = {4};
//+
Surface Loop(5) = {26, 11, 21, 16, 6, 5};
//+
Volume(5) = {5};
//+
Physical Surface("bottom_outlet") = {1};
//+
Physical Surface("base_top") = {2};
//+
Physical Surface("layer_1_top") = {3};
//+
Physical Surface("layer_2_top") = {4};
//+
Physical Surface("layer_3_top") = {5};
//+
Physical Surface("layer_4_top") = {6};
//+
Physical Surface("sidewall_right") = {7, 8, 9, 10, 11};
//+
Physical Surface("sidewall_left") = {12, 13, 14, 15, 16};
//+
Physical Surface("end_back") = {17, 18, 19, 20, 21};
//+
Physical Surface("end_front") = {22, 23, 24, 25, 26};
//+
Physical Volume("base") = {1};
//+
Physical Volume("layer_1") = {2};
//+
Physical Volume("layer_2") = {3};
//+
Physical Volume("layer_3") = {4};
//+
Physical Volume("layer_4") = {5};
//+
Field[1] = Box;
//+
Field[1].VIn = 0.05;
//+
Field[1].VOut = 1;
//+
Field[1].XMax = 0.25;
//+
Field[1].YMax = 0.188;
//+
Field[1].YMin = 0.0625;
//+
Field[1].ZMax = 0.21;
//+
Field[1].ZMin = 0.03;
//+
Background Field = 1;
//+
Field[1].XMax = 0.5;

//+
Transfinite Line {1, 2, 3, 4, 29, 26, 8, 5, 27, 6, 28, 7} = 10 Using Progression 1;
//+
Transfinite Surface {17} = {3, 15, 13, 1};
//+
Transfinite Surface {22} = {2, 4, 16, 14} Right;
//+
Recombine Surface {17, 7, 22, 12, 2, 1};
