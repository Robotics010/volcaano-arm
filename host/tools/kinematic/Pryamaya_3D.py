import math
import numpy as np 
#------------------------------------------------------------------------------------------------------------------
def s(x):
    if x == 0 or x == math.pi:
        return(float(0))
    else:
        return(math.sin(x))
#------------------------------------------------------------------------------------------------------------------
def c(x):
    if x == math.pi / 2 or x == math.pi * 3 / 2:
        return(float(0))
    else:
        return(math.cos(x))
#------------------------------------------------------------------------------------------------------------------
q1 = math.pi / 180 * float(input('Введите q1:'))
q2 = math.pi / 180 * float(input('Введите q2:'))
q3 = math.pi / 180 * float(input('Введите q3:'))
q4 = math.pi / 180 * float(input('Введите q4:'))
#------------------------------------------------------------------------------------------------------------------
#d1 = float(input('Введите d1:'))
#d2 = float(input('Введите d2:'))
#d3 = float(input('Введите d3:'))
#d4 = float(input('Введите d4:'))
#------------------------------------------------------------------------------------------------------------------
#alpha1 = math.pi / 180 * float(input('Введите alpha1:'))
#alpha2 = math.pi / 180 * float(input('Введите alpha2:'))
#alpha3 = math.pi / 180 * float(input('Введите alpha3:'))
#alpha4 = math.pi / 180 * float(input('Введите alpha4:'))
#------------------------------------------------------------------------------------------------------------------
#a1 = float(input('Введите a1:'))
#a2 = float(input('Введите a2:'))
#a3 = float(input('Введите a3:'))
#a4 = float(input('Введите a4:'))
#------------------------------------------------------------------------------------------------------------------
#Параметры Денавита-Хартенберга:
q = [q1, q2, q3, q4]
d = [148, 0, 0, 0]
alpha = [math.pi / 2, 0, 0, 0]
a = [0, 221, 222.5, 80]
#------------------------------------------------------------------------------------------------------------------
A1 = np.array([[c(q[0]), -c(alpha[0]) * s(q[0]), s(alpha[0]) * s(q[0]), a[0] * c(q[0])], 
              [s(q[0]), c(alpha[0]) * c(q[0]), -s(alpha[0]) * c(q[0]), a[0] * s(q[0])], 
              [0, s(alpha[0]), c(alpha[0]), d[0]], 
              [0, 0, 0, 1]])
A2 = np.array([[c(q[1]), -c(alpha[1])*s(q[1]), s(alpha[1]) * s(q[1]), a[1] * c(q[1])], 
              [s(q[1]), c(alpha[1]) * c(q[1]), -s(alpha[1]) * c(q[1]), a[1] * s(q[1])], 
              [0, s(alpha[1]), c(alpha[1]), d[1]], 
              [0, 0, 0, 1]])
A3 = np.array([[c(q[2]), -c(alpha[2])*s(q[2]), s(alpha[2]) * s(q[2]), a[2] * c(q[2])], 
              [s(q[2]), c(alpha[2]) * c(q[2]), -s(alpha[2]) * c(q[2]), a[2] * s(q[2])], 
              [0, s(0), c(alpha[2]), d[2]], 
              [0, 0, 0, 1]])
A4 = np.array([[c(q[3]), -c(alpha[3])*s(q[3]), s(alpha[3]) * s(q[3]), a[3] * c(q[3])], 
              [s(q[3]), c(alpha[3]) * c(q[3]), -s(alpha[3]) * c(q[3]), a[3] * s(q[3])], 
              [0, s(alpha[3]), c(alpha[3]), d[3]], 
              [0, 0, 0, 1]])
#------------------------------------------------------------------------------------------------------------------
A = [A1, A2, A3, A4]
T = np.eye(4)
for i in A:
    T = np.dot(T, i)
#------------------------------------------------------------------------------------------------------------------
#Положение схвата:
Px = [T[0,3]]
Py = [T[1,3]]
Pz = [T[2,3]]
P = [Px, Py, Pz]
#Ориентация схвата:
X4 = [T[0, 0], T[1, 0], T[2, 0]]
Y4 = [T[0, 1], T[1, 1], T[2, 1]]
Z4 = [T[0, 2], T[1, 2], T[2, 2]]
O = [X4, Y4, Z4]
print('Положение схвата: X =', P[0], 'Y=', P[1], 'Z=', P[2] )
print('Ориентация схвата: X =', O[0], 'Y=', O[1], 'Z=', O[2])