[node start]
ifflag=realizedTruth,true_end
text=……目が覚めた。
text=頭が重い。喉が渇いている。
text=見知らぬ部屋。扉は閉ざされている。
choice=部屋を見回す,look_room
choice=扉を調べる,door
choice=自分の状態を確認する,self_check

; ===================================
; 自分確認
; ===================================

[node self_check]
text=手が震えている。
text=爪の間に赤黒いものがこびりついている。
setflag=noticedHands
choice=部屋を見る,look_room
choice=戻る,start

; ===================================
; 部屋探索
; ===================================

[node look_room]
text=部屋には机、ベッド、窓、本棚がある。
choice=机を調べる,desk
choice=ベッドを調べる,bed
choice=窓を調べる,window
choice=本棚を調べる,bookshelf
choice=考える,think_check
choice=戻る,start

; ===================================
; 机
; ===================================

[node desk]
text=古びた写真が置かれている。
text=自分と、もう一人の男が写っている。
setflag=sawPhoto
choice=写真の裏を見る,photo_back
choice=引き出しを開ける,drawer
choice=戻る,look_room

[node photo_back]
text=裏には日付と住所。
text=——この部屋の住所だ。
setflag=checkedPhotoBack
choice=戻る,desk

[node drawer]
ifflag=foundKey,drawer_after
text=引き出しを開ける。
text=中に小さな鍵が入っている。
setflag=foundKey
text=鍵を手に入れた。
choice=戻る,desk

[node drawer_after]
text=引き出しは空だ。
choice=戻る,desk

; ===================================
; 本棚
; ===================================

[node bookshelf]
ifflag=foundDiary,bookshelf_after
text=本棚には雑誌と一冊の日記帳。
setflag=foundDiary
text=日記を手に取る。
choice=読む,read_diary
choice=戻る,look_room

[node bookshelf_after]
text=日記の存在が頭から離れない。
choice=戻る,look_room

[node read_diary]
text=『あいつは全てを奪った』
text=『計画は今夜実行する』
setflag=readDiary
choice=戻る,look_room

; ===================================
; ベッド
; ===================================

[node bed]
ifflag=readMemo,bed_after
text=ベッドの下に何かある。
setflag=readMemo
text=メモだ。
text=『真実から目を逸らすな』
choice=戻る,look_room

[node bed_after]
text=何もない。
choice=戻る,look_room

; ===================================
; 窓
; ===================================

[node window]
ifflag=sawBlood,window_after
text=窓枠に赤黒い染み。
setflag=sawBlood
text=……血？
choice=戻る,look_room

[node window_after]
text=乾いた血痕。
choice=戻る,look_room

; ===================================
; 扉
; ===================================

[node door]
ifflag=foundKey,unlock_door
text=鍵が必要だ。
choice=戻る,start

[node unlock_door]
text=鍵を差し込む。
text=重い音がして錠が外れた。
choice=扉を開ける,exit_attempt
choice=戻る,start

; ===================================
; 思考チェック（破綻しない段階式）
; ===================================

[node think_check]
ifflag=noticedHands,think_stage1
text=まだ材料が足りない気がする。
choice=戻る,look_room

[node think_stage1]
ifflag=sawPhoto,think_stage2
text=手の汚れが気になる。
choice=戻る,look_room

[node think_stage2]
ifflag=readDiary,think_stage3
text=写真の男の存在が引っかかる。
choice=戻る,look_room

[node think_stage3]
ifflag=sawBlood,truth_realize
text=計画という言葉が頭をよぎる。
choice=戻る,look_room

; ===================================
; 真相
; ===================================

[node truth_realize]
setflag=realizedTruth
text=全てが繋がった。
text=写真の男は被害者。
text=復讐は実行された。
text=そして実行したのは——自分。
choice=扉を開ける,true_end
choice=目を背ける,normal_end

; ===================================
; EXIT
; ===================================

[node exit_attempt]
ifflag=realizedTruth,true_end
text=闇へ踏み出す。
choice=外へ出る,bad_end
choice=考え直す,look_room

; ===================================
; ENDINGS
; ===================================

[node bad_end]
text=あなたは闇へ消えた。
text=次の瞬間、足場が崩れる。
text=——罠だった。
end=Bad

[node normal_end]
text=あなたは部屋を後にした。
text=だが真実から目を背けた。
text=罪は、追いかけてくる。
end=Normal

[node true_end]
text=扉の向こうに待っていたのは警察だった。
text=あなたは静かに手を差し出す。
text=全てを思い出した。
text=逃げない。
text=これが、自分の選んだ結末だ。
end=True