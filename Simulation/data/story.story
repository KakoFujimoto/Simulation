[node start]
text=目を覚ますと、見慣れない天井があった。
text=白い蛍光灯が低く唸り、空気はひどく乾いている。
text=どうやら、ここは病室のようだ。
choice=周囲を見回す,look_around
choice=そのまま横になる,stay_bed

[node look_around]
text=ゆっくりと身体を起こす。
text=点滴台、カーテン、簡素な棚。
text=棚の上には、小さなメモ帳が置かれている。
choice=メモ帳を手に取る,read_memo
choice=窓の外を見る,look_window

[node stay_bed]
text=もう少しだけ、このままでいよう。
text=身体が鉛のように重い。
text=意識が、再び沈んでいく……。
choice=無理やり起き上がる,look_around
choice=眠りに身を任せる,bad_end_sleep

[node read_memo]
text=メモ帳を開く。
text=走り書きの文字が、いくつか残されていた。
text=「ここから出ろ」
text=「彼らに見つかるな」
text=……誰の字だろうか。
choice=さらにページをめくる,read_more
choice=メモ帳を戻す,look_window

[node read_more]
text=最後のページに、強く書き殴られた一文があった。
text=「ドアを開ける前に、必ず音を確かめろ」
choice=ドアに近づく,go_door
choice=やはり窓を見る,look_window

[node look_window]
text=カーテンを少しだけ開く。
text=外は、夜だった。
text=街灯の光が、やけに遠く感じる。
text=ここは……本当に病院なのだろうか？
choice=ドアに向かう,go_door
choice=カーテンを閉じる,stay_room

[node stay_room]
text=嫌な予感がして、部屋に留まることにした。
text=そのとき——
text=廊下の向こうから、足音が聞こえた。
choice=息を潜める,hide
choice=ドアを開ける,open_door_fast

[node hide]
text=ベッドに戻り、布団を被る。
text=足音は、確実にこちらへ近づいてくる。
text=……。
text=やがて、足音は通り過ぎていった。
choice=今度こそドアに向かう,go_door
choice=もう少し様子を見る,stay_room

[node go_door]
text=ドアの前に立つ。
text=メモの言葉を思い出す。
text=「音を確かめろ」
choice=耳を澄ます,listen
choice=勢いよくドアを開ける,open_door_fast

[node listen]
text=ドアに耳を当てる。
text=……今は、何も聞こえない。
choice=静かにドアを開ける,open_door_slow
choice=やっぱりやめる,stay_room

[node open_door_slow]
text=きぃ……と、わずかに音を立ててドアが開く。
text=廊下には、誰もいない。
text=非常灯の赤い光だけが、静かに灯っている。
choice=廊下を進む,good_end_escape
choice=部屋に戻る,stay_room

[node open_door_fast]
text=勢いよくドアを開けた。
text=——その瞬間。
text=目の前に、人影が立っていた。
text=「……見つけた」
choice=抵抗する,bad_end_caught
choice=声を上げる,bad_end_caught

[node good_end_escape]
text=あなたは廊下を駆け出した。
text=もう振り返らない。
text=ここがどこで、何が起きているのかは分からない。
text=それでも——
text=生きて、外に出る。
text=そう、強く決めた。
text=【GOOD END】

[node bad_end_sleep]
text=意識が、完全に闇へ沈んだ。
text=次に目覚めることはなかった。
text=【BAD END】

[node bad_end_caught]
text=視界が、暗転する。
text=誰かの声が、遠くで響いている。
text=もう、選択肢はなかった。
text=【BAD END】