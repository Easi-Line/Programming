import { Request, Response } from 'express';
import ReportService from '../services/reportService';

class ReportController {
    private reportService: ReportService;

    constructor() {
        this.reportService = new ReportService();
    }

    public generateReport = async (req: Request, res: Response): Promise<void> => {
        try {
            const reportData = await this.reportService.createReport(req.body);
            res.status(201).json(reportData);
        } catch (error) {
            res.status(500).json({ message: 'Error generating report', error });
        }
    };

    public getReports = async (req: Request, res: Response): Promise<void> => {
        try {
            const reports = await this.reportService.fetchReports();
            res.status(200).json(reports);
        } catch (error) {
            res.status(500).json({ message: 'Error fetching reports', error });
        }
    };
}

export default ReportController;