# Programm for solving square equations
**ax2 + bx + c = 0** - type of eqution.
____
## Description of programm working<br>
- After starting programm greet you and asks if you want to solve: <br>

<img width="319" alt="Снимок экрана 2022-08-26 в 14 46 01" src="https://user-images.githubusercontent.com/74832034/186896649-d30659e0-8ba9-474c-8f31-3667eb777515.png"> <br>
____
- If you print 'n' programm stops. <br>
____
- If you print 'y' programm asks coefficients: <br>

<img width="369" alt="Снимок экрана 2022-08-26 в 14 50 47" src="https://user-images.githubusercontent.com/74832034/186897335-9ca07347-21be-427d-b949-cf3d4bfaf81d.png"> <br>
____
- If input is not 'y' or 'n' programm tell you what you are wrong: <br>

<img width="252" alt="Снимок экрана 2022-08-26 в 14 53 08" src="https://user-images.githubusercontent.com/74832034/186897651-913ec75a-3871-4abe-9ddf-5b39464f8532.png"> <br>
____
- If coefficients printed with mistake progamm tell you about it: <br>

<img width="373" alt="Снимок экрана 2022-08-26 в 15 06 15" src="https://user-images.githubusercontent.com/74832034/186899854-1860ba30-367a-4523-8857-be9f0b624a50.png"><br>
____
- If input is ok programm prints solution(s): <br>

<img width="373" alt="Снимок экрана 2022-08-26 в 15 02 25" src="https://user-images.githubusercontent.com/74832034/186899243-c73a4f9a-bf6a-47e1-8010-ca47d9668bb7.png"> <br>
____
- Also you can use command line argument -h what print path to programm folder: <br>

<img width="373" alt="Снимок экрана 2022-08-26 в 15 03 53" src="https://user-images.githubusercontent.com/74832034/186899461-8a159f04-8d67-4de6-bf4c-b17ea1172279.png"><br>
____
## Unit tests
You can start testing with tests what written in test.txt <br>
For debug write in header.h this: <br>
```
    #define DEBUG
```
if you want to write your own tests make them like this:<br>
2 1 6 5 -1 -5 <br>
1 1 2 1 -1 <br>
0 1 1 1 <br>
-1 0 0 0 <br>
It means: <br>
| Number of roots | a | b | c | root 1 | root 2 |
|-----------------|---|---|---|--------|--------|
|2                |1  | 6 | 5 |-1      |-5      |
|1                |1  |2  |  1|-1      |        |
|0                |1  |1  |1  |        |        |
|-1               |0  |0  |0  |        |        |

