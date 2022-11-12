    *= $0200

BEGIN
    LDA #$20
    LDA $0200
    CMP #$10
    BNE BEGIN