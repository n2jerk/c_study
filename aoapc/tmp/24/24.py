##趣味24点游戏
import itertools as itrs
EPS = 1e-6 # 极小值 ε epsilon
ops = itrs.product(r'+-*/',repeat=3) 
fmt = [
    '{A}{x}{B}{y}{C}{z}{D}',
    '{A}{x}(({B}{y}{C}){z}{D})',
    '(({A}{x}{B}){y}{C}){z}{D}',
    '({A}{x}{B}){y}({C}{z}{D})',
    '({A}{x}({B}{y}{C}){z}{D}',
    '{A}{x}({B}{y}({C}{z}{D}))'
]
# s = input('输入4个数字，以空格分隔，例：5 5 2 4\n>')
s='1 2 3 4'
nums = set(itrs.permutations(map(str,map(float, s.split()))))
formula = set()
cnt=0
for f,n,op in itrs.product(fmt, nums, ops):
    f = f.format(**dict(itrs.chain(zip('ABCD', n),zip('xyz', op))))
    try:
        if (f not in formula) and (abs(eval(f)-24.) < EPS) : 
            cnt+=1
            if cnt>10:break;
            print(f.replace('.0',''),'= 24')
            formula.add(f)
    except :
        continue 
# input('-结束-')