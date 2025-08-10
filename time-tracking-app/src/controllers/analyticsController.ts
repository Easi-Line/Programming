export class AnalyticsController {
    constructor(private analyticsService: any) {}

    async getProductivityAnalytics(req: any, res: any) {
        try {
            const analyticsData = await this.analyticsService.calculateProductivity();
            res.status(200).json(analyticsData);
        } catch (error) {
            res.status(500).json({ message: 'Error retrieving productivity analytics', error });
        }
    }

    async getTimeSpent(req: any, res: any) {
        try {
            const timeSpentData = await this.analyticsService.getTimeSpent();
            res.status(200).json(timeSpentData);
        } catch (error) {
            res.status(500).json({ message: 'Error retrieving time spent data', error });
        }
    }
}