[node start]
ifflag=readMemo,after_memo
text=ここは静かな部屋だ。
choice=部屋を見回す,look_room
choice=外に出る,end

[node look_room]
text=部屋には机とベッドがある。
choice=机を調べる,desk
choice=ベッドを調べる,bed
choice=戻る,start

[node desk]
text=机の上には何もない。
choice=戻る,look_room

[node bed]
setflag=readMemo
text=ベッドの下から一枚のメモを見つけた。
text=「外に出る前に、忘れ物はないか？」
choice=戻る,start

[node after_memo]
text=さっき見つけたメモの言葉が気になる。
text=何か大切なことを忘れている気がする。
choice=外に出る,end

[node end]
text=あなたは部屋を後にした。
text=静かな扉の音が背後で閉まる。