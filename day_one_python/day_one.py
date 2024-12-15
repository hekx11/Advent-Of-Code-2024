import pandas as pd

f = pd.read_csv('input.txt',sep="   ", header = None)

df1 = f[0]
df2 = f[1]

result = 0
count = 0
while len(df1) > 0:
   count += 1
   result += abs(min(df1) - min(df2))
   df1 = df1.drop(df1.idxmin())
   df2 = df2.drop(df2.idxmin())
print(result)