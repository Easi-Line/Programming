import { Router } from 'express';
import ProjectController from '../controllers/projectController';

const router = Router();
const projectController = new ProjectController();

export function setProjectRoutes(app: Router) {
    app.post('/projects', projectController.createProject.bind(projectController));
    app.get('/projects', projectController.getProjects.bind(projectController));
    app.put('/projects/:id', projectController.updateProject.bind(projectController));
}