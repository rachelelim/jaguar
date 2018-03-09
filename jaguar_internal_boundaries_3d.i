[Mesh]
  file = 3d_moving_v2.msh
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
    scaling = 1e-1
  [../]
[]

[Functions]
# Assign different thermal conductivity along time to materials in different layers
  [./material_layer2]
    type = ParsedFunction
    value = 'if(t>0.004,0.0067,0.0000)' # Thermal conductivity W/mm*K
  [../]
  [./material_layer3]
    type = ParsedFunction
    value = 'if(t>0.008,0.0067,0.0000)' # Thermal conductivity W/mm*K
  [../]
[]

[Kernels]
  [./heat_conduction]
    type = HeatConduction
    # diffusion_coefficient = 0.0067 # Thermal conductivity W/mm*K
    variable = temperature
  [../]
  [./heat_conduction_time_derivative]
    type = HeatConductionTimeDerivative
    # density_name = 0.00443 # g/mm^3
    # specific_heat = 0.526 # J/g-K
    variable = temperature
  [../]
[]

[DiracKernels]
 [./point_heat_source]
   type = MovingDirac3d
   variable = temperature
   value = 150 # (W)
   point = '0 0.2 0.208'
 [../]
[]

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = bottom_outlet
    value = 296 # (K)
  [../]
[]

[Materials]
  # Update conductivity of materials along simulation time
  [./Ti64_base]
    type = GenericConstantMaterial
    block = base
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer1]
    type = GenericConstantMaterial
    block = layer_1
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer2_conduct]
    type = GenericFunctionMaterial
    block = layer_2
    prop_names = 'thermal_conductivity'
    prop_values = material_layer2
  [../]
  [./Ti64_layer2]
    type = GenericConstantMaterial
    block = layer_2
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer3_conduct]
    type = GenericFunctionMaterial
    block = layer_3
    prop_names = 'thermal_conductivity'
    prop_values = material_layer3
  [../]
  [./Ti64_layer3]
    type = GenericConstantMaterial
    block = layer_3
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
[]

[Problem]
  type = FEProblem
  # coord_type = RZ
  # rz_coord_axis = X
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-10
  l_tol = 1e-08
  num_steps = 150
  end_time = 0.012
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
