export class BillingController {
    constructor(private billingService: BillingService) {}

    calculateBilling(req: Request, res: Response) {
        const { projectId } = req.body;
        const billingAmount = this.billingService.calculateBilling(projectId);
        res.json({ projectId, amount: billingAmount });
    }

    getBillingReports(req: Request, res: Response) {
        const reports = this.billingService.getBillingReports();
        res.json(reports);
    }
}