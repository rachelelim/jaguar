[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 400
  ny = 75
  nz = 50
  xmax = 4 # Length of test block
  ymax = 0.75 # Width of test block
  zmax = 0.5 # Thickness of test block
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
  [../]
[]

[AuxVariables]
  [./a] #For 3d visualization purpose
    initial_condition = 0
  [../]
[]

[Kernels]
  [./heat_conduction]
    type = HeatConduction
    variable = temperature
  [../]
  [./heat_conduction_time_derivative]
    type = HeatConductionTimeDerivative
    variable = temperature
  [../]
[]

[DiracKernels]
  [./point_heat_source]
    type = MovingDirac3dSingleBeaddxr750
    variable = temperature
    value = 153 # 300W * 0.51 absorptivity
    point = '0.5 0.375 0.495'
  [../]
[]

[AuxKernels]
  [./phase]
    type = ParsedAux
    variable = a
    args = temperature
    function = 'if(temperature>=1643,1,0)'
  [../]
[]

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = 'back'
    value = 296 # (K)
  [../]
[]

[Materials]
  [./IN718]
    type = GenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0114 0.435 0.008220' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
[]

[Problem]
  type = FEProblem
#  coord_type = RZ
#  rz_coord_axis = X
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-10
  l_tol = 1e-08
  num_steps = 100
  end_time = 0.003
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
