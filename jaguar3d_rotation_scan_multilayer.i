[Mesh]
  file = 3d_rotate_scan_multilayer.msh
[]

[Variables]
  [./temperature]
    initial_condition = 353 # Initial temperature
    #scaling = 1e3 # Multiply the PDE by the scaling number, use when the residual is too small/large to avoid computational inaccuracy
  [../]
[]

[Functions]
# Assign different thermal conductivity along time to materials in different layers
[./material_layer2]
  type = ParsedFunction
  value = 'if(t>= 0.081,0.0114,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer3]
  type = ParsedFunction
  value = 'if(t>= 0.162,0.0114,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer4]
  type = ParsedFunction
  value = 'if(t>= 0.243,0.0114,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer5]
  type = ParsedFunction
  value = 'if(t>= 0.324,0.0114,0.0000)' # Thermal conductivity W/mm*K
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
    type = rotation_scan_multilayer
    variable = temperature
    value = 145.35    #285W * 0.51
    point = '0.06 0.07 0.232'
  [../]
[]

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = 'bottom_outlet'
    value = 353 # (K)
  [../]
[]

[Materials]
  # Specific heat and density
  [./IN718_base]
    type = GenericConstantMaterial
    block = base
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0114 0.435 0.008220' # W/mm*K, J/g-K, g/mm^3 @ 296K //Chua et al. (2018) Fig.13
  [../]
  [./IN718_layer1]
    type = GenericConstantMaterial
    block = layer_1
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0114 0.435 0.008220' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./IN718_layer2]
    type = GenericConstantMaterial
    block = layer_2
    prop_names = 'specific_heat density'
    prop_values = '0.435 0.008220' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./IN718_layer3]
    type = GenericConstantMaterial
    block = layer_3
    prop_names = 'specific_heat density'
    prop_values = '0.435 0.008220' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./IN718_layer4]
    type = GenericConstantMaterial
    block = layer_4
    prop_names = 'specific_heat density'
    prop_values = '0.435 0.008220' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./IN718_layer5]
    type = GenericConstantMaterial
    block = layer_5
    prop_names = 'specific_heat density'
    prop_values = '0.435 0.008220' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  #Inactive layer thermal conductivity
  [./IN718_layer2_conduct]
    type = GenericFunctionMaterial
    block = layer_2
    prop_names = 'thermal_conductivity'
    prop_values = material_layer2
  [../]
  [./IN718_layer3_conduct]
    type = GenericFunctionMaterial
    block = layer_3
    prop_names = 'thermal_conductivity'
    prop_values = material_layer3
  [../]
  [./IN718_layer4_conduct]
    type = GenericFunctionMaterial
    block = layer_4
    prop_names = 'thermal_conductivity'
    prop_values = material_layer4
  [../]
  [./IN718_layer5_conduct]
    type = GenericFunctionMaterial
    block = layer_5
    prop_names = 'thermal_conductivity'
    prop_values = material_layer5
  [../]
[]

[Problem]
  type = FEProblem
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-10
  l_tol = 1e-08 # Use to control the number of linear iteration, can help to lower the non-linear residual when it is not converge
  num_steps = 5550
  end_time = 0.555
  solve_type = 'PJFNK' # Preconditioning Jacobian Free Newton-Keylov
  petsc_options_iname = '-pc_type -pc_hypre_type' #pc: Preconditioning // Hypre: parallel high performance preconditioners (library)
  petsc_options_value = 'hypre boomeramg' # mg: multigrid
[]


[Outputs]
  exodus = true
  file_base = ../../../../Volumes/BlackMesa_storage/dinowu_storage/MOOSE/output/multilayer_rotation_scan_June2019/rotation
[]
