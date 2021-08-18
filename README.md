# ojichat-python
ojichatのPythonラッパーです

# 使い方
```py
import ojichat

ojichat.generate()
# => 何かしらのおじさんの文言
```
```py
def generate(name: str = "", num: int = 4, level: int = 0) -> str:
    """
    おじさんの文言を生成する関数です

    name:
        名前です。空文字をしているとランダムな名前を使用します
    num:
        絵文字、顔文字の最大連続数です
    level:
        句読点挿入頻度レベルです
        1から3の範囲で指定する必要があります
    """
```


# インストール
```
pip install ojichat
```
### 必要な物
- Python 3.6 以上
- Go 1.12 以上
