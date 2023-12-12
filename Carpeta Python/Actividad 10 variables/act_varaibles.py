from scipy.optimize import linprog

Coef = [-5, -8, -6, 0, 0, 0, 0, 0, 0, 0]

M_Rest = [
    [2, 4, 3, -1, 0, 0, 0, 0, 0, 0],
    [3, 2, 5, 0, -1, 0, 0, 0, 0, 0],
    [-5, 0, 0, 0, 0, 1, 0, 0, 0, 0],
    [0, 6, 0, 0, 0, 0, 2, 0, 0, 0],
    [0, 0, 4, 0, 0, 0, 0, 3, 0, 0],
    [1, 1, 1, 0, 0, 0, 0, 0, 1, 0],
    [0, 0, 0, -1, 0, 0, 0, 0, 0, 1]
]

M_Coef = [1, 1, 5, 6, 4, 1, 1]

limites = (0, None)


result = linprog(Coef, A_ub=M_Rest, b_ub=M_Coef, bounds=[limites], method='highs')


print("Beneficio maximo ", -result.fun)
print("Cantidad de productos A: ", result.x[0])
print("Cantidad de productos B: ", result.x[1])
print("Cantidad de productos C: ", result.x[2])
print("Horas de mano de obra utilizadas: ", result.x[3])
print("Horas de máquinas utilizadas: ", result.x[4])
print("Cantidad de materia prima utilizada para A: ", result.x[5])
print("Cantidad de materia prima utilizada para B: ", result.x[6])
print("Cantidad de materia prima utilizada para C: ", result.x[7])
print("Producción total de productos: ", result.x[8])
print("Cantidad de horas de trabajo utilizadas: ", result.x[9])
