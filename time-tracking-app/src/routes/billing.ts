import { Router } from 'express';
import BillingController from '../controllers/billingController';

const router = Router();
const billingController = new BillingController();

export function setBillingRoutes(app: Router) {
    app.post('/billing/calculate', billingController.calculateBilling);
    app.get('/billing/reports', billingController.getBillingReports);
}