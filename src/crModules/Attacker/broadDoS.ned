package dos.crModules.Attacker;
import dos.core.*;

simple broadDoS extends Attacker like IAttacker
{
    parameters:
        double starttime = default(0.0);   // Attack start time
        double stoptime = default(10000000000.0);    // Attack stop time
        bool Attack_hop = default(true);
        double idle = default(0.05);
        double busy = default(0.05);
       
    @class(broadDoS);
    @signal[attackStart](type="long");  // The signals emited by app layer  // from int
    @statistic[attackStart](title="AttackStart"; source="attackStart"; record=count);
    @signal[attackEnd](type="long");
    @statistic[attackEnd](title="AttackEnd"; source="attackEnd"; record=count);
}

module sillyDoS extends BaseAttacker
{
    Type = "broadDoS";
    //@display("i=./images/antenna");
}