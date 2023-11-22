from scipy.optimize import linprog

# Vector de coeficientes de la función objetivo (negativos porque linprog realiza minimización)
Coef = [120, 200]  # Cambié los coeficientes para reflejar una maximización

# Matriz de Coeficientes para las restricciones 
M_Rest = [[-1, -1],
          [-1, 0],
          [0, -1], 
          [-60, -24]]

# Matriz de coeficientes para las desigualdades
M_Coef = [-65, -23, -20, -3000]

# Defininiendo los Límites para x e y (cantidad mínima de trajes y vestidos)
limites = [(0, None), (0, None)]

# Resolviendo el problema de programación lineal
result = linprog(Coef, A_ub=M_Rest, b_ub=M_Coef, bounds=limites, method='highs')

# Imprimiendo los resultados
print("Cantidad de asignaturas de informatica:", round(result.x[0]))
print("Cantidad de asignaturas de bio/quim:", round(result.x[1]))
print("Horas de estudio:", result.fun)  # La función objetivo ahora es positiva