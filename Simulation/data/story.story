[node start]
ifflag=realizedTruth,true_end
text=……目が覚めた。
text=見知らぬ部屋。扉は閉ざされている。
choice=部屋を見回す,look_room
choice=扉を調べる,door

[node look_room]
text=部屋には机、ベッド、そして小さな窓がある。
choice=机を調べる,desk
choice=ベッドを調べる,bed
choice=窓を調べる,window
choice=考える,think
choice=戻る,start

[node desk]
text=机の上には古びた写真が置かれている。
text=……写っているのは、自分？
text=しかし背景はこの部屋ではない。
choice=引き出しを開ける,drawer
choice=戻る,look_room

[node drawer]
ifflag=foundKey,drawer_after
text=引き出しの中には小さな鍵が入っている。
setflag=foundKey
text=鍵を手に入れた。
choice=戻る,desk

[node drawer_after]
text=引き出しは空だ。
choice=戻る,desk

[node bed]
ifflag=readMemo,bed_after
text=ベッドの下に何か落ちている。
setflag=readMemo
text=一枚のメモだ。
text=「真実から目を逸らすな」
choice=戻る,look_room

[node bed_after]
text=ベッドの下にはもう何もない。
choice=戻る,look_room

[node window]
ifflag=sawBlood,window_after
text=窓は固く閉ざされている。
text=窓枠に赤黒い染みがある。
setflag=sawBlood
text=……血？
choice=戻る,look_room

[node window_after]
text=乾いた血痕が残っている。
choice=戻る,look_room

[node door]
ifflag=foundKey,unlock_door
text=扉は固く閉ざされている。
text=鍵が必要だ。
choice=戻る,start

[node unlock_door]
text=鍵を差し込み、ゆっくり回す。
text=カチリ、と音がする。
choice=扉を開ける,exit_attempt
choice=戻る,start

[node exit_attempt]
ifflag=sawBlood,truth_hint
text=扉の向こうは暗闇だ。
choice=外へ出る,bad_end
choice=部屋に戻る,start

[node truth_hint]
text=血痕のことが頭をよぎる。
text=……この部屋で何があった？
choice=もう一度部屋を調べる,look_room
choice=外へ出る,normal_end

[node think]
text=集めた情報を整理する。
ifflag=readMemo,check_blood
text=まだ手がかりが足りない気がする。
choice=戻る,look_room

[node check_blood]
ifflag=sawBlood,check_key
text=何か重要なものを見落としている。
choice=戻る,look_room

[node check_key]
ifflag=foundKey,truth_realize
text=鍵……？
choice=戻る,look_room

[node truth_realize]
setflag=realizedTruth
text=全てが繋がった。
text=この部屋は事件現場。
text=そして犯人は——自分だ。
choice=扉を開ける,true_end
choice=まだ調べる,look_room


; =========================
; BAD END
; =========================
[node bad_end]
text=あなたは暗闇へ足を踏み出した。
text=次の瞬間、足元が崩れる。
text=——罠だった。
end=Bad


; =========================
; NORMAL END
; =========================
[node normal_end]
text=あなたは部屋を後にした。
text=しかし真実を知らないまま。
text=——胸に重たい何かを抱えながら。
end=Normal


; =========================
; TRUE END
; =========================
[node true_end]
text=写真、血痕、メモ……
text=全ては一つの真実を指している。
text=ここは事件現場だ。
text=あなたは記憶を失っていただけだった。
text=扉を開ける。
text=そこに待っていたのは、警察だった。
end=True