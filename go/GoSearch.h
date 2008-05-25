//----------------------------------------------------------------------------
/** @file GoSearch.h
    Class GoSearch extends SgSearch
*/
//----------------------------------------------------------------------------

#ifndef GOSEARCH_H
#define GOSEARCH_H

#include "SgSearch.h"

class GoBoard;

//----------------------------------------------------------------------------

/** Go search.
    Defines EndOfGame to return true after two passes.
*/
class GoSearch
    : public SgSearch
{
public:
    GoSearch(GoBoard& board, SgSearchHashTable* hash);

    void AddMoveProp(SgNode* node, SgMove move, SgBlackWhite player);

    GoBoard& Board();

    const GoBoard& Board() const;

    /** Return false, because some Go searches require it.
        @todo Remove. Implement it in the subclasses, because it depends on
        the move generation there.
    */
    bool CheckDepthLimitReached() const;

    bool EndOfGame() const;

    /** Default implementation of SgSearch::Execute() for Go searches.
        Executes the move is legal.
        Updates the trace node (this should be done in SgSearch::CallExecute!)
    */
    bool Execute(SgMove move, int* delta, int depth);

    /** Default implementation of SgSearch::GetHashCode() for Go searches.
        @return Board().GetHashCodeInclToPlay().
    */
    SgHashCode GetHashCode() const;

    /** Default implementation of SgSearch::ToPlay() for Go searches.
        @return Board().ToPlay().
    */
    SgBlackWhite GetToPlay() const;

    void SetToPlay(SgBlackWhite toPlay);

    std::string MoveString(SgMove move) const;

    /** Default implementation of SgSearch::TakeBack() for Go searches.
        Takes back the move on the board.
        Updates the trace node (this should be done in SgSearch::CallExecute!)
    */
    void TakeBack();

private:
    GoBoard& m_board;
};

inline GoBoard& GoSearch::Board()
{
    return m_board;
}

inline const GoBoard& GoSearch::Board() const
{
    return m_board;
}

//----------------------------------------------------------------------------

#endif // GOSEARCH_H
