[node start]
text=……目を覚ます。
text=天井が、やけに近い。
text=白い蛍光灯が、低い音で唸っている。
text=身体を動かそうとして、気づいた。
text=——ここは、どこだ？
choice=周囲を確認する,room_check

[node room_check]
text=簡素な病室だ。
text=ベッド、点滴台、カーテン、閉じたドア。
text=窓の外は、真っ暗で何も見えない。
choice=ベッドの周囲を見る,bed_check
choice=ドアに近づく,door_first

[node bed_check]
text=ベッドの脇に、落ちかけのメモ帳がある。
text=「まだ出るな」
text=「上に行くな」
text=不自然なほど、文字が強く書かれている。
choice=ドアに向かう,door_first

[node door_first]
text=ドアの前に立つ。
text=——カツ、カツ。
text=廊下の向こうから、規則正しい足音が聞こえる。
choice=耳を澄ます,listen
choice=すぐにドアを開ける,open_fast

[node listen]
text=足音は、ドアの前で止まった。
text=……ノックはない。
text=そのまま、遠ざかっていく。
choice=廊下に出る,hallway

[node open_fast]
text=勢いよくドアを開けた。
text=廊下には誰もいない。
text=だが、床に濡れた足跡が残っている。
text=それは——病室の中へ続いていた。
choice=無視して進む,hallway

[node hallway]
text=非常灯の赤い光が、長い廊下を照らしている。
text=ナースステーションは無人だ。
choice=階段を探す,find_stairs

[node find_stairs]
text=突き当たりに階段がある。
text=上と下、どちらにも行けそうだ。
choice=上へ行く,go_up
choice=下へ行く,go_down

; ====== BAD END ======
[node go_up]
text=階段を上る。
text=……何段上っても、景色が変わらない。
text=息が切れ、視界が歪む。
text=背後から、あの足音が聞こえた。
text=「まだ、戻れません」
text=意識が暗転する。
text=【BAD END】

; ====== NORMAL END ======
[node go_down]
text=階段を下りる。
text=冷たい空気が、肌を刺す。
text=扉の先に、非常出口の表示があった。
choice=外に出る,exit_out
choice=扉を閉める,return_inside

[node exit_out]
text=扉を押し開ける。
text=夜風が、頬を打つ。
text=外だ。
text=振り返ると、建物の名前は剥がされていた。
text=ここが何だったのか、分からないままだ。
text=【NORMAL END】

; ====== GOOD END ======
[node return_inside]
text=嫌な予感がして、扉を閉めた。
text=代わりに、壁の案内図が目に入る。
text=「治験病棟　B3」
text=……思い出した。
text=自分は、ここに「同意」して来たのだ。
choice=記憶を辿る,true_end_room

[node true_end_room]
text=管理室に辿り着く。
text=モニターには、自分の生体反応。
text=——ベッドに横たわる、もう一人の自分。
text=これは、離脱テストだ。
text=意識だけが、外に出ていた。
text=「被験者、帰還します」
text=視界が白く染まる。
text=【GOOD END】
