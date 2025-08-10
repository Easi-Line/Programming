import express from 'express';
import { setTimeLogRoutes } from './routes/timeLogs';
import { setProjectRoutes } from './routes/projects';
import { setReportRoutes } from './routes/reports';
import { setAnalyticsRoutes } from './routes/analytics';
import { setBillingRoutes } from './routes/billing';

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());

setTimeLogRoutes(app);
setProjectRoutes(app);
setReportRoutes(app);
setAnalyticsRoutes(app);
setBillingRoutes(app);

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});