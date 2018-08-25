[Mesh]
  file = 3d_overhang.msh
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
    #scaling = 1e3 # Multiply the PDE by the scaling number, use when the residual is too small/large to avoid computational inaccuracy
  [../]
[]

[Functions]
# Assign different thermal conductivity along time to materials in different layers
[./material_layer2]
  type = ParsedFunction
  value = 'if(t>=0.406,0.0067,0.0000)' # Thermal conductivity W/mm*K
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
    type = MovingDirac3d_overhang_a
    variable = temperature
    value = 24
    point = '0.1 0.1 0.2'
  [../]
[]

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = 'bottom_outlet'
    value = 296 # (K)
  [../]
[]

[Materials]
  # Specific heat and density
  [./Ti64_base]
    type = GenericConstantMaterial
    block = base
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0008 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K //Chua et al. (2018) Fig.13
  [../]
  [./Ti64_layer1]
    type = GenericConstantMaterial
    block = layer_1
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer2]
    type = GenericConstantMaterial
    block = layer_2
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  #Inactive layer thermal conductivity
  [./Ti64_layer2_conduct]
    type = GenericFunctionMaterial
    block = layer_2
    prop_names = 'thermal_conductivity'
    prop_values = material_layer2
  [../]
[]

[Problem]
  type = FEProblem
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-10
  l_tol = 1e-08 # Use to control the number of linear iteration, can help to lower the non-linear residual when it is not converge
  num_steps = 812
  end_time = 0.812
  solve_type = 'PJFNK' # Preconditioning Jacobian Free Newton-Keylov
  petsc_options_iname = '-pc_type -pc_hypre_type' #pc: Preconditioning // Hypre: parallel high performance preconditioners (library)
  petsc_options_value = 'hypre boomeramg' # mg: multigrid
[]


[Outputs]
  exodus = true
[]
