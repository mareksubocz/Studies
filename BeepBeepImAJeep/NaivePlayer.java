package put.ai.games.naiveplayer;

import java.util.List;
import java.util.Random;
import put.ai.games.game.Board;
import put.ai.games.game.Move;
import put.ai.games.game.Player;

public class NaivePlayer extends Player {

    private Random random = new Random(0xdeadbeef);
    private Move najlepszyRuch;
    private static int MAXDEPTH = 10;

    // TODO uzyj normalnej funkcji
    public int max(int a, int b) {
        if (a >= b)
            return a;
        return b;
    }

    public int ocenaStanu(Board b, Color color) {
        if (b.getWinner(color) == getColor()) {
            return Integer.MAX_VALUE;
        } else if (b.getWinner(color) != null) {
            return -Integer.MAX_VALUE;
        }

        int score = 0;
        for(int y=0;y<b.getSize();y++){
            for(int x=0;x<b.getSize();x++){
                score += ocenaStanuPola(b,color,x,y,0,1);
                score += ocenaStanuPola(b,color,x,y,1,1);
                score += ocenaStanuPola(b,color,x,y,1,0);
                score += ocenaStanuPola(b,color,x,y,1,-1);
                score -= ocenaStanuPola(b,getOpponent(color),x,y,0,1);
                score -= ocenaStanuPola(b,getOpponent(color),x,y,1,1);
                score -= ocenaStanuPola(b,getOpponent(color),x,y,1,0);
                score -= ocenaStanuPola(b,getOpponent(color),x,y,1,-1);
            }
        }
        return score;
//        return random.nextInt(24) - 12;
    }

    public int ocenaStanuPola(Board b, Color color, int x, int y, int dx, int dy){
        if(b.getState(x,y) != color){
            return 0;
        }
        int l=0, xi=x+dx, yi=y+dy, lim=b.getSize()/2 + b.getSize()/4+1, d=0;
        while(xi<b.getSize() && yi<b.getSize() && d<lim){
            if(b.getState(xi,yi) == getOpponent(color)){
                break;
            }
            l++;
            d++;
            xi+=dx;
            yi+=dy;
        }
        xi=x-dx;
        yi=y-dy;
        d=0;
        while(xi<b.getSize() && yi<b.getSize() && d<lim){
            if(b.getState(xi,yi) == getOpponent(color)){
                break;
            }
            l++;
            d++;
            xi-=dx;
            yi-=dy;
        }
        return l;
    }

    public int alphaBeta(Board b, int depth, int alpha, int beta, Color color) {

        if (b.getWinner(color) != null || depth == 0) { // zaczynamy od MAXDEPTH
            return (ocenaStanu(b, color));
        }

        List<Move> moves = b.getMovesFor(getColor());
        int val = 0;

        if (color == getColor()) { // type == MAX
            for (Move move : moves) {
                b.doMove(move);
                val = alphaBeta(b, depth - 1, alpha, beta, getOpponent(getColor()));
                b.undoMove(move);
                alpha = max(val, alpha);
                if (alpha >= beta) {
                    if (depth == MAXDEPTH - 1)
                        najlepszyRuch = move; // FIXME: sprawdz
                    return beta; // cutoff
                }
            }
            return alpha;
        } else { // type == MIN
            for (Move move : moves) {
                b.doMove(move);
                val = alphaBeta(b, depth - 1, alpha, beta, getColor());
                b.undoMove(move);
                beta = max(-val, -beta); // min
                if (alpha >= beta) {
                    if (depth == MAXDEPTH - 1)
                        najlepszyRuch = move; // FIXME: sprawdz
                    return alpha; // cutoff
                }
            }
            return beta;
        }
    }

    @Override
    public String getName() {
        return "Marek Subocz 136806 Jacek Gulij 136714";
    }

    @Override
    public Move nextMove(Board b) {
        int result = alphaBeta(b, MAXDEPTH, -Integer.MAX_VALUE, Integer.MAX_VALUE, getColor());
        System.out.println(result);
        return najlepszyRuch;
    }
}
