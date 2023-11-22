from scipy.optimize import linprog

Coef = [-7, -4, -3]

M_Rest = [[1, 2, 2],
          [2, 1, 2]]

M_Coef = [30, 45]

limites = [(0, None), (0, None), (0, None)]

result = linprog(Coef, A_ub=M_Rest, b_ub=M_Coef, bounds=limites, method='highs')

print("Cantidad de cerveza rubia:", round(result.x[0]))
print("Cantidad de cerveza negra:", round(result.x[1]))
print("Cantidad de cerveza de baja graduación:", round(result.x[2]))
print("Beneficio maximo:", -(result.fun))