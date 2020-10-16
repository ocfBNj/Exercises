import urllib.request
import urllib.parse
import re
import json
import os

headers = {
    "cookie": "",  # TODO
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.72"
}


def save_source_code(rid: str, save_path: str, language: str, save_encoding: str = 'utf-8'):
    global headers

    req = urllib.request.Request(
        f"https://www.luogu.com.cn/record/{rid}", headers=headers)

    http_data = urllib.request.urlopen(req).read().decode('utf-8')
    ret = re.findall(
        r'<script>window._feInjection = JSON\.parse\(decodeURIComponent\("(.*)"\)\);window._feConfigVersion=1602133664;<\/script>',
        http_data)

    if len(ret):
        result = urllib.parse.unquote(ret[0])

        json_data = json.loads(result)

        pid: str = json_data['currentData']['record']['problem']['pid']

        if f"{pid}.{language}" in os.listdir(save_path):
            print(f"文件{pid}.{language}已存在！")
            return

        try:
            source_code: str = json_data['currentData']['record']['sourceCode']

            with open(f"{save_path}{pid}.{language}", 'wb') as file:
                file.write(source_code.encode('utf-8'))

            print(f"保存{save_path}{pid}.{language}成功！")
        except KeyError:
            print(f"你还没有做过{pid}，无法获取源代码！")


def get_ac_record(user: str, page: int):
    global headers

    req = urllib.request.Request(
        f"https://www.luogu.com.cn/record/list?user={user}&status=12&page={page}&_contentOnly=1",
        headers=headers)

    data = urllib.request.urlopen(req).read().decode('utf-8')
    json_data = json.loads(data)

    li = []

    print(f"开始获取第{page}页记录...")

    for i in range(len(json_data['currentData']['records']['result'])):
        language = json_data['currentData']['records']['result'][i]['language']

        if language == 3 or language == 4 or language == 11 or language == 12:
            language = 'cpp'
        elif language == 7:
            language = 'py'
        elif language == 14:
            language = 'go'
        elif language == 17:
            language = 'cs'
        else:
            print(f"未知语言，位于第{page}页{i + 1}条记录")
            language = 'xxx'

        li.append(
            (str(json_data['currentData']['records']['result'][i]['id']), str(language)))

    print(f"第{page}页获取完成！\n")

    return li


def start(uid: str, page: tuple):
    for i in range(page[0], page[1] + 1):
        li = get_ac_record(uid, i)
        for rid in li:
            save_source_code(rid[0], 'records/', rid[1])


if __name__ == "__main__":
    if headers["cookie"] == "":
        headers["cookie"] = input("输入cookie: ")

    start(uid='180023', page=(1, 14))
    print("所有记录保存成功！")
