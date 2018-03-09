//+
Point(1) = {0, 0, 0, 1.0};
//+
Point(2) = {0, 0.25, 0, 1.0};
//+
Point(3) = {0, 0.5, 0, 1.0};
//+
Point(4) = {0, 0.75, 0, 1.0};
//+
Point(5) = {0, 1, 0, 1.0};
//+
Point(6) = {4, 0, 0, 1.0};
//+
Point(7) = {4, 0.25, 0, 1.0};
//+
Point(8) = {4, 0.5, 0, 1.0};
//+
Point(9) = {4, 0.75, 0, 1.0};
//+
Point(10) = {4, 1, 0, 1.0};
//+
Line(1) = {5, 4};
//+
Line(2) = {4, 3};
//+
Line(3) = {3, 2};
//+
Line(4) = {2, 1};
//+
Line(5) = {10, 9};
//+
Line(6) = {9, 8};
//+
Line(7) = {8, 7};
//+
Line(8) = {7, 6};
//+
Line(9) = {5, 10};
//+
Line(10) = {4, 9};
//+
Line(11) = {3, 8};
//+
Line(12) = {7, 2};
//+
Line(13) = {1, 6};
//+
Line Loop(1) = {9, 5, -10, -1};
//+
Plane Surface(1) = {1};
//+
Line Loop(2) = {10, 6, -11, -2};
//+
Plane Surface(2) = {2};
//+
Line Loop(3) = {11, 7, 12, -3};
//+
Plane Surface(3) = {3};
//+
Line Loop(4) = {12, 4, 13, -8};
//+
Plane Surface(4) = {4};
//+
Physical Line("side_wall_left") = {1, 2, 3, 4};
//+
Physical Line("side_wall_right") = {5, 6, 7, 8};
//+
Physical Line("bottom_outlet") = {13};
//+
Physical Line("layer_1_top") = {12};
//+
Physical Line("layer_2_top") = {11};
//+
Physical Line("layer_3_top") = {10};
//+
Physical Line("layer_4_top") = {9};
//+
Physical Surface("layer_4") = {1};
//+
Physical Surface("layer_3") = {2};
//+
Physical Surface("layer_2") = {3};
//+
Physical Surface("layer_1") = {4};
