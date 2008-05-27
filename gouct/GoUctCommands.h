//----------------------------------------------------------------------------
/** @file GoUctCommands.h
*/
//----------------------------------------------------------------------------

#ifndef GOUCTCOMMANDS_H
#define GOUCTCOMMANDS_H

#include <string>
#include "GtpEngine.h"

class GoBoard;
class GoPlayer;
class GoUctGlobalSearchPlayer;
class GoUctBoard;
class GoUctSearch;
class GoUctGlobalSearch;
template<class BOARD> class GoUctDefaultPlayoutPolicy;

//----------------------------------------------------------------------------

/** GTP commands for GoUctGlobalSearchPlayer and players implementing
    GoUctObjectWithSearch.
    Basic set of GTP commands for class GoUctGlobalSearchPlayer.
*/
class GoUctCommands
{
public:
    /** Constructor.
        @param bd The game board.
        @param player Reference to pointer to current player, this player can
        be null or a different player, but those commands of this class that
        need a GoUctGlobalSearchPlayer will fail, if the current player is not
        GoUctGlobalSearchPlayer.
    */
    GoUctCommands(GoBoard& bd, GoPlayer*& player);

    void AddGoGuiAnalyzeCommands(GtpCommand& cmd);

    /** @page gouctgtpcommands GoUctCommands Commands
        - @link CmdBounds() @c uct_bounds @endlink
        - @link CmdEstimatorStat() @c uct_estimator_stat @endlink
        - @link CmdGfx() @c uct_gfx @endlink
        - @link CmdMoves() @c uct_moves @endlink
        - @link CmdParamGlobalSearch() @c uct_param_globalsearch @endlink
        - @link CmdParamPolicy() @c uct_param_policy @endlink
        - @link CmdParamPlayer() @c uct_param_player @endlink
        - @link CmdParamSearch() @c uct_param_search @endlink
        - @link CmdPatterns() @c uct_patterns @endlink
        - @link CmdPolicyMoves() @c uct_policy_moves @endlink
        - @link CmdRaveValues() @c uct_rave_values @endlink
        - @link CmdRootFilter() @c uct_root_filter @endlink
        - @link CmdSaveGames() @c uct_savegames @endlink
        - @link CmdSaveTree() @c uct_savetree @endlink
        - @link CmdSequence() @c uct_sequence @endlink
        - @link CmdSignatureCode() @c uct_signature_code @endlink
        - @link CmdSignatureCount() @c uct_signature_count @endlink
        - @link CmdSignatureValue() @c uct_signature_value @endlink
        - @link CmdScore() @c uct_score @endlink
        - @link CmdStatPlayer() @c uct_stat_player @endlink
        - @link CmdStatPlayerClear() @c uct_stat_player_clear @endlink
        - @link CmdStatPolicy() @c uct_stat_policy @endlink
        - @link CmdStatPolicyClear() @c uct_stat_policy_clear @endlink
        - @link CmdStatSearch() @c uct_stat_search @endlink
        - @link CmdValue() @c uct_value @endlink
    */
    /** @name Command Callbacks */
    // @{
    // The callback functions are documented in the cpp file
    void CmdBounds(GtpCommand& cmd);
    void CmdEstimatorStat(GtpCommand& cmd);
    void CmdGfx(GtpCommand& cmd);
    void CmdMoves(GtpCommand& cmd);
    void CmdParamGlobalSearch(GtpCommand& cmd);
    void CmdParamPolicy(GtpCommand& cmd);
    void CmdParamPlayer(GtpCommand& cmd);
    void CmdParamSearch(GtpCommand& cmd);
    void CmdPatterns(GtpCommand& cmd);
    void CmdPolicyMoves(GtpCommand& cmd);
    void CmdRaveValues(GtpCommand& cmd);
    void CmdRootFilter(GtpCommand& cmd);
    void CmdSaveGames(GtpCommand& cmd);
    void CmdSaveTree(GtpCommand& cmd);
    void CmdScore(GtpCommand& cmd);
    void CmdSequence(GtpCommand& cmd);
    void CmdSignatureCode(GtpCommand& cmd);
    void CmdSignatureCount(GtpCommand& cmd);
    void CmdSignatureValue(GtpCommand& cmd);
    void CmdStatPlayer(GtpCommand& cmd);
    void CmdStatPlayerClear(GtpCommand& cmd);
    void CmdStatPolicy(GtpCommand& cmd);
    void CmdStatPolicyClear(GtpCommand& cmd);
    void CmdStatSearch(GtpCommand& cmd);
    void CmdValue(GtpCommand& cmd);
    // @} // @name

    void Register(GtpEngine& engine);

private:
    GoBoard& m_bd;

    GoPlayer*& m_player;

    GoUctGlobalSearch& GlobalSearch();

    GoUctGlobalSearchPlayer& Player();

    GoUctDefaultPlayoutPolicy<GoUctBoard>& Policy(std::size_t threadId);

    void Register(GtpEngine& e, const std::string& command,
                  GtpCallback<GoUctCommands>::Method method);

    GoUctSearch& Search();
};

//----------------------------------------------------------------------------

#endif // GOUCTCOMMANDS_H