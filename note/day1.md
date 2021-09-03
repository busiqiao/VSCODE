# python爬虫基础
## day1.1代码如下
```
#include
import time
import requests
from multiprocessing.dummy import Pool

'''
def calc_power2(num):
    return num * num


pool = Pool(3)
origin_num = [x for x in range(10)]
result = pool.map(calc_power2, origin_num)
print(f'计算0-9的平方：{result}')
'''


def query(url):
    requests.get(url)


start = time.time()
for i in range(100):
    query('https://baidu.com')
end = time.time()
print(f'单线程循环访问100次百度首页，耗时：{end - start}')

start = time.time()
url_list = []
for i in range(100):
    url_list.append('https://baidu.com')
pool = Pool(5)
pool.map(query, url_list)
end = time.time()
print(f'5线程访问100次百度首页，耗时：{end - start}')
```
[百度](http://baidu.com)

**你是煞笔**
hell