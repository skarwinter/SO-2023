from scipy.optimize import linprog

Coef = [-100, -80, -150]

M_Rest = [[36, 30, 60],
          [20, 18, 25],
          [3, 2, 5]]

M_Coef = [4800, 2400, 375]

limites = [(0, None), (0, None), (0, None)]

result = linprog(Coef, A_ub=M_Rest, b_ub=M_Coef, bounds=limites, method='highs')

print("Cantidad de camisas:", round(result.x[0]))
print("Cantidad de shorts:", round(result.x[1]))
print("Cantidad de pantalones:", round(result.x[2]))
print("Utilidad maxima:", -(result.fun))