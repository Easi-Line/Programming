import { Router } from 'express';
import AnalyticsController from '../controllers/analyticsController';

const router = Router();
const analyticsController = new AnalyticsController();

export function setAnalyticsRoutes(app: Router) {
    app.get('/analytics/productivity', analyticsController.getProductivityAnalytics.bind(analyticsController));
    app.get('/analytics/time-spent', analyticsController.getTimeSpent.bind(analyticsController));
}