import { Router } from 'express';
import TimeLogController from '../controllers/timeLogController';

const router = Router();
const timeLogController = new TimeLogController();

export const setTimeLogRoutes = (app) => {
    app.use('/api/timelogs', router);
    router.post('/', timeLogController.createTimeLog.bind(timeLogController));
    router.get('/', timeLogController.getTimeLogs.bind(timeLogController));
    router.delete('/:id', timeLogController.deleteTimeLog.bind(timeLogController));
};