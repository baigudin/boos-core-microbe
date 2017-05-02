$NOMOD51



?c_c51startup   SEGMENT   CODE

?stack          SEGMENT   IDATA
                RSEG      ?stack
                DS        1

                EXTRN     CODE (?c_start)
                PUBLIC    ?c_startup

                CSEG      AT 0
?c_startup:     ljmp      startup1

                RSEG      ?c_c51startup

startup1:

                mov       sp, #?stack-1
                ljmp      ?c_start

                END
