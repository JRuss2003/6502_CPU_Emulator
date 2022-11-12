    *= $0200

BEGIN
    LDA #$20
    LDA $200F
    CMP #$10
    BNE BEGIN