import { Router } from 'express';
import ReportController from '../controllers/reportController';

const router = Router();
const reportController = new ReportController();

export const setReportRoutes = (app) => {
    app.use('/reports', router);
    router.get('/', reportController.getReports.bind(reportController));
    router.post('/generate', reportController.generateReport.bind(reportController));
};