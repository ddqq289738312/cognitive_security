

import dos.core.*;
package dos.crModules.SpectrumSensor;

simple crSpecSensor extends BaseSpecSensor like ISpecSensor
{
    parameters:
        double sensingDuration = default(0.1);  				// How much time does channel sensing take!
        double sensingConsumption = default(0.1); 			// How much energy is consumed by sensing!
        // How many times does the node sweep through all channel with sensing until finding free channel.
        int sensingIterations @signal[sensing](type="int") = default(3);
        int sensingPattern = default(1);  // 1 for continuous, 2 for Patterned.
        @display("i=block/wtx");
        @class(crSpecSensor);
        
        // Statistics
        @signal[sensingSignal](type="long");  // from int
    	@statistic[sensingSignal](title="Spectrum Sensing"; source="sensingSignal"; record=count,vector);
}